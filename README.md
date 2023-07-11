

The aim of this project is to illustrate how to generate and call a dynamic library (DLL) in Windows.

There are two approaches used to export C++ symbols to a DLL:
the first approach, which we'll call declspec, is based upon the__declspec keyword.

-  ``__declspec(dllexport)``: exports symbols to a DLL
-  ``__declspec(dllimport)``: imports symbols from a DLL.

The second approach, which we will call the DEF approach, consists in writing a symbol definition file to be exported to a DLL. 

In this small repository:

- **A**: we use the ``__declspec`` approach to first export symbols to a DLL (``A.dll``), and then import these symbols into a main program ``test.cpp``.
We implement a header file (``A.hpp``) in which we simply switch from export to import with a ``-DA_EXPORTS`` key, which we pass to CMake when we compile.
Note that anyhow Cmake/Visual will define this flag (see [DLL MSVC](https://learn.microsoft.com/fr-fr/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=msvc-170 )).

- **B**: Here, we use the DEF approach and omit the use of ``__declspec``. We implement a definition file (``B.def``) in which we put the symbols associated with the functions we want to export/import to the DLL. 

  Note that writing this file can be a bit tricky, as the symbols are extracted from the ``dumpbin`` command applied to the ``B.lib`` file.

- **C**: CMake provides the macro ``CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS`` which, if set to ON, automatically generates the associated DEF file.

  In this example, all symbols are automatically exported.

- **test.cpp**: the main program in which we call the different libraries (A, B and C).


Compiling
=========

This example can be built with ``cmake`` and ``msbuild``
```console

call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
mkdir build
cd build
cmake -DCMAKE_GENERATOR:STRING="Visual Studio 15 2017 Win64" -DCMAKE_INSTALL_PREFIX:PATH=d\workspace\dll-howto\bin ..
msbuild /p:Configuration=Release /p:Platform=x64 ALL_BUILD.vcxproj
msbuild /p:Configuration=Release /p:Platform=x64 INSTALL.vcxproj

```

Running
=======
This example can be run by typing in a cmd terminal:

```console
  cd bin
  call test.exe
```


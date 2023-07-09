
The aim of this mini-project is to show you how to generate and call a dynamic library (DLL) under Windows.

There are two approaches used to export symbols to a DLL:
the first approach, which we'll call declspec, is based on the__declspec function.

-  ``__declspec(dllexport)``: exports symbols to a DLL
-  ``__declspec(dllimport)``: imports symbols from a DLL.

The second approach, which we will call the DEF approach, consists of writing a symbol definition file to be exported to a DLL. 

In this small repository:

- **A**: we use the ``__declspec`` approach to first export symbols to a DLL (``A.dll``), and then import these symbols into a main program ``test.cpp``.
We implement a header file (``A.hpp``) in which we simply switch from export to import with a ``-DA_EXPORTS`` key, which we pass to CMake when we compile.

- **B**: Here, we use the DEF approach and omit the use of ``__declspec``. We implement a definition file (``B.def``) in which we put the symbols associated with the functions we want to export/import to the DLL. 

  Note that writing this file can be a bit tricky, as the symbols are extracted from the ``dumpbin`` command applied to the ``B.obj`` object file.

- **C**: CMake provides the macro ``CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS`` which, if set to ON, automatically generates the associated DEF file.

  In this example, all symbols are automatically exported.

- **E**: contains the main program in which we call the various libraries.


Compiling
=========

This example can be built with ``cmake`` and ``msbuild``
```console

call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
mkdir build
cd build
cmake -DCMAKE_GENERATOR:STRING="Visual Studio 15 2017 Win64" -DCMAKE_INSTALL_PREFIX:PATH=d\workspace\dll-tester\bin ..
msbuild /p:Configuration=Release /p:Platform=x64 ALL_BUILD.vcxproj
msbuild /p:Configuration=Release /p:Platform=x64 INSTALL.vcxproj


Running
=======
This example can be run by typing in a cmd terminal:

```console
  cd bin
  call test.exe
```

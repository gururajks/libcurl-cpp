# libcurl-cpp
Using Libcurl in cpp with Visual studio 2017
Instructions:
- You have to compile and build the source yourself otherwise the dlls and libs wont be compatible.
- clone the github repo - https://github.com/curl/curl
- cd curl
- buildconf.bat
- Prepare the command prompt with environment variables by running: 
`“C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\vc\Auxiliary\Build\vcvarsall.bat” x64`
or run it on native tools command prompt
- cd winbuild
- `nmake /f Makefile.vc mode=static VC=14` This worked for me. (there are other options you can try as well)
- cd ../builds folder and enter the folder that looks mostly like this: `libcurl-vc-x64-release-static` depending on your options
- copy the bin, lib and include folder into your project 

VS Settings
- Include the path to libcurl.lib (or whatever the name of the lib in your /lib folder that is generated)
in Additional Library Directories under Properties -> Linker
- Included libcurl.lib in Additional Dependencies under Linker -> Input -> Additional Dependencies
- Place `CURL_STATICLIB` in Properties -> C/C++ -> Preprocessor -> Preprocessor Definitions


References:
You can follow this link as well: pretty much the same instructions (if my instructions dont work)
https://medium.com/@chuy.max/compile-libcurl-on-windows-with-visual-studio-2017-x64-and-ssl-winssl-cff41ac7971d
Another link: https://store.chipkin.com/articles/building-libcurl-on-windows-with-mt-and-mtd


Note
- If using Visual Studio and Creating a windows console project make sure pch.h header is always on the top in your 
cpp files otherwise you will get all kinds of errors

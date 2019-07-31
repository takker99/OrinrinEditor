if(Test-Path .\x64\Release\){
    Copy-Item -Path .\package -Destination .\OrinrinEditor-x64\ -Recurse

    Copy-Item -Path .\x64\Release\OrinrinEditor.exe -Destination .\OrinrinEditor-x64\
    Copy-Item -Path .\x64\Release\sqlite3.dll -Destination .\OrinrinEditor-x64\
    Compress-Archive -DestinationPath OrinrinEditor-x64.zip -Path .\OrinrinEditor-x64
}

if(Test-Path .\Release\){
    Copy-Item -Path .\package\ -Destination .\OrinrinEditor-x86\ -Recurse

    Copy-Item -Path .\Release\OrinrinEditor.exe -Destination .\OrinrinEditor-x86\
    Copy-Item -Path .\Release\sqlite3.dll -Destination .\OrinrinEditor-x86\
    Copy-Item -Path .\Library\lib\imgctl.dll -Destination .\OrinrinEditor-x86\
    Compress-Archive -DestinationPath OrinrinEditor-x86.zip -Path .\OrinrinEditor-x86
}
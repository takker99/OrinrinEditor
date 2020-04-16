if(Test-Path .\x64\Release\){
    Copy-Item -Path .\package -Destination .\OrinrinEditor-x64\ -Recurse

    Copy-Item -Path .\x64\Release\OrinrinEditor.exe -Destination .\OrinrinEditor-x64\
    Copy-Item -Path .\x64\Release\sqlite3.dll -Destination .\OrinrinEditor-x64\
    & "C:\Program Files\7-Zip\7z.exe" a .\OrinrinEditor-x64.zip .\OrinrinEditor-x64\
}

if(Test-Path .\Release\){
    Copy-Item -Path .\package\ -Destination .\OrinrinEditor-x86\ -Recurse

    Copy-Item -Path .\Release\OrinrinEditor.exe -Destination .\OrinrinEditor-x86\
    Copy-Item -Path .\Release\sqlite3.dll -Destination .\OrinrinEditor-x86\
    Copy-Item -Path .\Library\lib\imgctl.dll -Destination .\OrinrinEditor-x86\
    & "C:\Program Files\7-Zip\7z.exe" a .\OrinrinEditor-x86.zip .\OrinrinEditor-x86\
}
param(
    [string]$cppFile,
    [string]$inputFile = ".\input.txt"
)

# Compile
g++ $cppFile -o test

# Run with input piped in
Get-Content $inputFile | .\test.exe

# Clean up
Remove-Item .\test.exe -Force

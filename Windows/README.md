# Windows

## 概要

### PS
GET-WinEvent System | Where-Object{$_.Id -eq 6005 -or $_.Id -eq 6006 -or $_.Id -eq 6008 -or $_.Id -eq
 7002 -or $_.Id -eq 7001} | select-Object TImeCreated,Id,Message | export-CSV "C:\xxx\output.csv" -Encoding UTF8

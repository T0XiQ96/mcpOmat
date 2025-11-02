Param(
    [string]$ArduinoCliPath = "arduino-cli"
)

Write-Output "Installing Arduino cores required for PitterOmat v2..."

$cores = @(
    "arduino:avr",
    "esp32:esp32"
)

foreach ($core in $cores) {
    $cmd = @($ArduinoCliPath, "core", "install", $core)
    Write-Output ("Executing: {0}" -f ($cmd -join " "))
    & $cmd
    if ($LASTEXITCODE -ne 0) {
        throw "Failed to install Arduino core '$core'."
    }
}

Write-Output "Arduino core installation complete."

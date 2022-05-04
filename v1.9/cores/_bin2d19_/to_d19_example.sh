./bin2d19 nes/fpga_nes.bin _d19/nes.d19 -n "NES" -sl "nes/*.nes" 0 -v "0.0.1" -d "\n\7NES Core\n\n\0Keys:\n\5Z X C V\0 - SELECT START B A\n\51 2\0 - controller 1/2\n\5F1\0 - 512x480\n\5F2\0 - 640x480\n\5F3\0 - HQ scaler\n\5F11\0 - reset\n\5F12\0 - exit"

./bin2d19 spectrum/spectrum.bin _d19/spectrum.d19 -n "ZX Spectrum 128" -fl "128-0.ROM" 100000 -fl "128-1.ROM" 104000 -fl "ESXMMC.ROM" 180000 -v "0.0.1"

./bin2d19 Next186_SoC/diy_d19.bin _d19/Next186_SoC.d19 -n "Next186_SoC" -fl "BIOS_Next186.ROM" F4000 -v "0.6"

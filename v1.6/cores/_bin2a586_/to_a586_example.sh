
./bin2a586 amiga/amiga.bin _a586/amiga.a586 -n "AMIGA" -rn "Kickstart 1.3" -fb "KICK13.ROM" 780000 -fb "KICK13.ROM" 7C0000 -rn "Kickstart 3.1" -fb "KICK31.ROM" 780000 -rn "Kickstart 3.1 + SD" -fb "KICK31SD.ROM" 780000 -rn "Kickstart 3.1.4" -fb "KICK314.ROM" 780000 -rn "Kickstart 3.1.4 + SD" -fb "KICK314SD.ROM" 780000 -rn "SD" -sb "*.ROM" 780000 -d "\n\7Amiga core\n\n\5PrScr\0 - change resolution" -v "0.3"
./bin2a586 amiga/amiga.bin _a586/amiga_13.a586 -auto -n "AMIGA (Kick 1.3)" -fb "KICK13.ROM" 780000 -fb "KICK13.ROM" 7C0000 -d "\n\7Amiga core\n\n\5PrScr\0 - change resolution" -v "0.3"
./bin2a586 amiga/amiga.bin _a586/amiga_31sd.a586 -auto -n "AMIGA (Kick 3.1 SD)" -fb "KICK31SD.ROM" 780000 -d "\n\7Amiga core\n\n\5PrScr\0 - change resolution" -v "0.3"
./bin2a586 amiga/amiga.bin _a586/amiga_314sd.a586 -auto -n "AMIGA (Kick 3.1.4 SD)" -fb "KICK314SD.ROM" 780000 -d "\n\7Amiga core\n\n\5PrScr\0 - change resolution" -v "0.3"

./bin2a586 amiga_ami_KBM/amiga.bin _a586/amiga_ami_KBM.a586 -n "AMIGA (AMI_KB&M)" -rn "Kickstart 1.3" -fb "KICK13.ROM" 780000 -fb "KICK13.ROM" 7C0000 -rn "Kickstart 3.1" -fb "KICK31.ROM" 780000 -rn "Kickstart 3.1 + SD" -fb "KICK31SD.ROM" 780000 -rn "Kickstart 3.1.4" -fb "KICK314.ROM" 780000 -rn "Kickstart 3.1.4 + SD" -fb "KICK314SD.ROM" 780000 -rn "SD" -sb "*.ROM" 780000 -v "0.3"
./bin2a586 amiga_ami_KBM/amiga.bin _a586/amiga_ami_KBM_13.a586 -auto -n "AMIGA (AMI_KB&M Kick 1.3)" -fb "KICK13.ROM" 780000 -fb "KICK13.ROM" 7C0000 -v "0.3"
./bin2a586 amiga_ami_KBM/amiga.bin _a586/amiga_ami_KBM_31sd.a586 -auto -n "AMIGA (AMI_KB&M Kick 3.1 SD)" -fb "KICK31SD.ROM" 780000 -v "0.3"
./bin2a586 amiga_ami_KBM/amiga.bin _a586/amiga_ami_KBM_314sd.a586 -auto -n "AMIGA (AMI_KB&M Kick 3.1.4 SD)" -fb "KICK314SD.ROM" 780000 -v "0.3"

./bin2a586 nes/fpga_nes.bin _a586/nes.a586 -n "NES" -sl "nes/*.nes" 0 -v "0.0.1" -d "\n\7NES Core\n\n\0Keys:\n\5Z X C V\0 - SELECT START B A\n\51 2\0 - controller 1/2\n\5F1\0 - 512x480\n\5F2\0 - 640x480\n\5F3\0 - HQ scaler\n\5F11\0 - reset\n\5F12\0 - exit"

./bin2a586 spectrum/spectrum.bin _a586/spectrum.a586 -n "ZX Spectrum 128" -fl "128-0.ROM" 100000 -fl "128-1.ROM" 104000 -fl "ESXMMC.ROM" 180000 -v "0.0.1"

./bin2a586 Next186_SoC/diy_a586.bin _a586/Next186_SoC.a586 -n "Next186_SoC" -fl "BIOS_Next186.ROM" F4000 -v "0.6"


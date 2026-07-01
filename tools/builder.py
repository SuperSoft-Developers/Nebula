import os
import sys

target = sys.argv[1]

print("🌌 Nebula Engine build:", target)

if target == "windows":
    os.system("gcc platform/windows_main.c core/*.c game/*.c -o build/nebula.exe")

elif target == "3ds":
    os.system("arm-none-eabi-gcc platform/3ds_main.c core/*.c game/*.c -o build/nebula.elf")
    print("✔ ELF gerado (use elf23ds para 3DSX)")

else:
    print("Target não suportado na Nebula Fase 1")

#!/bin/bash

cd symbol_export

assembler="$(find ${IDF_TOOLS_PATH:-../../../esp-idf-tools} -name riscv32-esp-elf-cc)"
echo Assembler $assembler

for libname in *; do
echo Exporting symbols in $libname
ident=`sed s/-/_/g <<< $libname`
./../symbol_export.py \
    --symbols $libname \
    --kbelf ../src/kbelf_lib_$ident.c --kbelf-id badge_elf_lib_$ident --kbelf-path lib$libname.so \
    --lib ../fakelib/lib$libname.so --assembler "$assembler" -F=-march=rv32imafc_zicsr_zifencei_xesppie -F=-mabi=ilp32f
done

# ./symbol_export.py \
#     --symbols symbol_export.txt \
#     --kbelf src/kbelf_lib.c --kbelf-id badge_elf_lib --kbelf-path libbadge.so \
#     --lib libbadge.so --assembler $(find ${IDF_TOOLS_PATH:-../../esp-idf-tools} -name riscv32-esp-elf-cc) -F=-march=rv32imafc_zicsr_zifencei_xesppie -F=-mabi=ilp32f

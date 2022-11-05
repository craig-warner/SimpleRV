OUTPUT_ARCH( "riscv" )
ENTRY(_start)

SECTIONS
{
  . = 0x00001000;
  .text.init : { *(.text.init) }
  . = ALIGN(0x1000);
  .data ALIGN(0x4000) : { *(.data) }
  .data ALIGN(0x4000) : { *(.rodata) }
  .bss : { *(.bss) }
  _end = .;
}

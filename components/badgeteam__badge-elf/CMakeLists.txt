idf_build_get_property(idf_arch IDF_TARGET_ARCH)
if("${idf_arch}" STREQUAL "riscv")
idf_component_register(
	SRCS
		"src/badge_elf.c"
		"src/kbelf_lib_badge.c"
		"src/kbelf_lib_c.c"
		"src/kbelf_lib_gcc.c"
		"src/kbelf_lib_m.c"
		"src/kbelf_lib_pax_gfx.c"
		"src/kbelf_lib_pax_codecs.c"
		"src/kbelf_lib_pthread.c"
		"src/kbelf_lib_plugin.c"
		"src/kbelfx.c"
		"kbelf/src/port/riscv.c"
		"kbelf/src/kbelf_dyn.c"
		"kbelf/src/kbelf_file.c"
		"kbelf/src/kbelf_inst.c"
		"kbelf/src/kbelf_reloc.c"
		"kbelf/src/kbelf.c"
	INCLUDE_DIRS
		"include"
		"kbelf/include"
	REQUIRES
		"badge-elf-api"
		"freertos"
)
endif()

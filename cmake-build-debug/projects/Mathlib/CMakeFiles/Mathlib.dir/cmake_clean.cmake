file(REMOVE_RECURSE
  "Mathlib.pdb"
  "Mathlib"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/Mathlib.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()

if [ ! -d results ]; then
    mkdir results/
fi

cd ../

# argument error
e_output_test "./cub3D cubfiles/error_case/normal.cub invalarg" "arg"
e_output_test "./cub3D cubfiles/error_case/invalid_extension.cubn" "arg"
e_output_test "./cub3D cubfiles/error_case/wrong_extension.com" "arg"
e_output_test "./cub3D cubfiles/error_case/non_extension" "arg"

# empty file error
e_output_test "./cub3D cubfiles/error_case/empty_e.cub" "cubfile"

# type error
e_output_test "./cub3D cubfiles/error_case/type_less_e.cub" "cubfile"
e_output_test "./cub3D cubfiles/error_case/type_duplicate_e.cub" "cubfile"
e_output_test "./cub3D cubfiles/error_case/type_wrong_alphabet_e.cub" "cubfile"
e_output_test "./cub3D cubfiles/error_case/type_extra_head_newline_e.cub" "cubfile"
e_output_test "./cub3D cubfiles/error_case/type_with_spaces_e.cub" "cubfile"
e_output_test "./cub3D cubfiles/error_case/type_only_e.cub" "cubfile"
e_output_test "./cub3D cubfiles/error_case/type_non_e.cub" "cubfile"

# xpm error
e_output_test "./cub3D cubfiles/error_case/xpm_nonexist_e.cub" "xpm"
e_output_test "./cub3D cubfiles/error_case/xpm_multi_path_e.cub" "xpm"
e_output_test "./cub3D cubfiles/error_case/xpm_with_spaces_e.cub" "xpm"

# color error
e_output_test "./cub3D cubfiles/error_case/color_separate_e.cub" "cubfile"
e_output_test "./cub3D cubfiles/error_case/color_alphabet_e.cub" "cubfile"
e_output_test "./cub3D cubfiles/error_case/color_non_e.cub" "cubfile"
e_output_test "./cub3D cubfiles/error_case/color_2_e.cub" "cubfile"
e_output_test "./cub3D cubfiles/error_case/color_4_e.cub" "cubfile"
e_output_test "./cub3D cubfiles/error_case/color_256_e.cub" "cubfile"
e_output_test "./cub3D cubfiles/error_case/color_minus_e.cub" "cubfile"
e_output_test "./cub3D cubfiles/error_case/color_intmax_e.cub" "cubfile"
e_output_test "./cub3D cubfiles/error_case/color_intmin_e.cub" "cubfile"
e_output_test "./cub3D cubfiles/error_case/color_with_spaces_e.cub" "cubfile"
e_output_test "./cub3D cubfiles/error_case/color_extra_head_comma_e.cub" "cubfile"
e_output_test "./cub3D cubfiles/error_case/color_extra_tail_comma_e.cub" "cubfile"

# order error
e_output_test "./cub3D cubfiles/error_case/order_map_not_last_e.cub" "cubfile"

# map error
e_output_test "./cub3D cubfiles/error_case/map_not_closed_e.cub" "map"
e_output_test "./cub3D cubfiles/error_case/map_wrong_alphabet_e.cub" "map"
e_output_test "./cub3D cubfiles/error_case/map_wrong_num_e.cub" "map"
e_output_test "./cub3D cubfiles/error_case/map_multi_player_e.cub" "map"
e_output_test "./cub3D cubfiles/error_case/map_extra_tail_newline_e.cub" "map"
e_output_test "./cub3D cubfiles/error_case/map_non_e.cub" "map"
# e_output_test "./cub3D cubfiles/error_case/map_too_big_e.cub" "map"

# open error
# *error type would change depends on the machine you are using
chmod 000 cubfiles/error_case/open_no_permission_e.cub
e_output_test "./cub3D cubfiles/error_case/open_no_permission_e.cub" "open"
chmod 755 cubfiles/error_case/open_no_permission_e.cub
e_output_test "./cub3D cubfiles/error_case/open_is_dir_e.cub" "open"

rm -r test/results

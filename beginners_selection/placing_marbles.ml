let d = int_of_char '0'
let () = Scanf.scanf "%c%c%c" (fun a b c ->
  print_endline @@ string_of_int (int_of_char a + int_of_char b + int_of_char c - 3 * d))

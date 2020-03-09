let w = Scanf.scanf " %s" (fun s -> s)
let () =
  String.iter (function
      | 'a' | 'i' | 'u' | 'e' | 'o' -> ()
      | ch -> print_char ch) w;
  print_newline ()

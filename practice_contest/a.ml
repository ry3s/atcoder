let () = Scanf.scanf "%d %d %d %s"
  (fun a b c s -> print_endline @@
                    ((string_of_int (a+b+c)) ^ " " ^ s))

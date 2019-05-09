let () = Scanf.scanf "%d %d" (fun a b ->
   print_endline @@ if (a * b) mod 2 = 0 then "Even" else "Odd")

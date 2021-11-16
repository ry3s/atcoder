let () =
  let x = Scanf.scanf "%d" Fun.id in
  let ans = 100 - (x mod 100) in
  print_int ans; print_newline ()

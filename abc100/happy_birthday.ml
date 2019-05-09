let () =
  let a, b = Scanf.scanf "%d %d" (fun a b -> a, b) in
  Printf.printf "%s\n" (if a <= 8 && b <= 8 then "Yay!" else ":(")

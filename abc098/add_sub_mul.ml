let () =
  Scanf.scanf "%d %d" (fun a b ->
      max (max (a + b) (a -b)) (a * b))
      |> Printf.printf "%d\n"
           

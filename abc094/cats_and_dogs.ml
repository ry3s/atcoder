let () =
  Scanf.scanf "%d %d %d" (fun a b x ->
      (if a + b >= x && a <= x then "YES" else "NO")
      |> Printf.printf "%s\n" )
                     
      

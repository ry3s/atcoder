let () =
  Scanf.scanf "%d %d %d %d" (fun a b c d ->
      if (abs(a-b) <= d && abs (b-c) <= d)
         || abs(a-c) <= d then
        "Yes"
      else
        "No")
  |> Printf.printf "%s\n"
             

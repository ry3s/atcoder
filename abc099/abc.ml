let () =
  let n = Scanf.scanf "%d\n" (fun n -> n) in
  (if n < 1000 then
    "ABC"
  else
    "ABD")
|> Printf.printf "%s\n"
      

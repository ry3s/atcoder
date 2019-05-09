let () =
  let s = Scanf.scanf "%s" (fun x -> x) in
  (if String.contains s 'a'
     && String.contains s 'b'
     && String.contains s 'c' then
    "Yes"
  else
    "No")
  |> Printf.printf "%s\n"

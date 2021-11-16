let () =
  let s = Scanf.scanf "%s\n" Fun.id in
  let rec loop i =
    if i >= String.length s then
      true
    else
      let is_upper = Char.code 'A' <= Char.code s.[i] && Char.code s.[i] <= Char.code 'Z' in
      if (i mod 2 = 0 && not is_upper) || (i mod 2 == 1 && is_upper) then
        loop (i + 1)
      else false
  in
  print_endline @@ if loop 0 then "Yes" else "No"

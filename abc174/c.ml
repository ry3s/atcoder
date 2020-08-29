let k = read_int ()

let rec loop i x =
  if x = 0 then i
  else if k < i then -1
  else loop (i + 1) ((10 * x + 7) mod k)

let () = Printf.printf "%d\n" @@ loop 1 (7 mod k)

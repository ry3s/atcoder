let n = Scanf.scanf " %d" Fun.id
let s = Scanf.scanf " %s" Fun.id

let rec loop left right n =
  if left >= right then n
  else if s.[left] = 'R' then loop (left + 1) right n
  else if s.[right] = 'W' then loop left (right - 1) n
  else loop (left + 1) (right - 1) (n + 1)

let () =
  Printf.printf "%d\n" @@ loop 0 (String.length s - 1) 0

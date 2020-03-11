let s = Scanf.scanf " %s" (fun x -> x)
let t = Scanf.scanf " %s" (fun x -> x)

let rec loop i =
  let index_opt s c = try Some (String.index s c) with _ -> None in
  if i = String.length s then
    print_endline "You can win"
  else if s.[i] = t.[i] then
    loop (i + 1)
  else if (s.[i] = '@' && index_opt "atcoder" t.[i] <> None)
          || (t.[i] = '@' && index_opt "atcoder" s.[i] <> None) then
    loop (i + 1)
  else
    print_endline "You will lose"

let () = loop 0

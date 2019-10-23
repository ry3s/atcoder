let s = read_line ();;
let n = String.length s;;
let chs = Array.to_list @@ Array.init n (fun i -> s.[i]);;
let () =
  let len = List.length @@ List.sort_uniq compare chs in
  let ans = if n = len then "yes" else "no" in
  print_endline ans;;

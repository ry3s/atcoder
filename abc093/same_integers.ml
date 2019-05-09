let () =
  let a, b, c = Scanf.scanf "%d %d %d" (fun a b c -> a, b, c) in
  let [x;y;z]  = List.rev @@ List.sort compare [a;b;c] in
  let n_xy = x - y in
  let n_yz = y - z in
  let res =
    if n_yz mod 2 = 0 then
      n_xy + n_yz / 2
    else
      n_xy + n_yz / 2 + 2
  in
  Printf.printf "%d\n" res
  


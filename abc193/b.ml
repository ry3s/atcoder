let _ =
  let n = read_int () in
  let stores =
    Array.init n (fun i -> Scanf.scanf "%d %d %d " (fun x y z -> (x, y, z)))
  in
  let ans =
    Array.fold_left
      (fun acc (a, p, x) ->
        if x - int_of_float (ceil (float a)) > 0 then min acc p else acc)
      max_int stores
  in
  Printf.printf "%d\n" (if ans = max_int then -1 else ans)

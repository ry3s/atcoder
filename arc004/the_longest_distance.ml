let () =
  let max = ref 0.0 in
  let n = Scanf.scanf "%d" (fun x -> x) in
  let xy = Array.init n (fun _ -> Scanf.scanf " %d %d" (fun x y -> (x, y))) in
  for i = 0 to (n-1) do
    for j = 0 to (n-1) do
      let x1, y1 = xy.(i) in
      let x2, y2 = xy.(j) in
      let d = sqrt (float ((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2))) in
      if d > !max then max := d else ()
    done;
  done;
  Printf.printf "%f\n" !max 
   

let () =
  let n = Scanf.scanf "%d" (fun n -> n) in
  let xs = Array.init n (fun _ -> Scanf.scanf " %d" (fun x -> x)) in
  let xs' = Array.copy xs in
  Array.sort compare xs';
  let m1 = xs'.(n/2 -1) in
  let m2 = xs'.(n/2) in
  for i = 0 to n-1 do
    Printf.printf "%d\n"
      (if xs.(i) <= m1 then m2 else m1)
  done;
  

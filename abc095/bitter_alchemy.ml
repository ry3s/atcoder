let () =
  let n, x = Scanf.scanf "%d %d\n" (fun n x -> n, x) in
  let mi = Array.init n (fun _ -> Scanf.scanf "%d\n" (fun x -> x)) in
  Array.sort (-) mi;
  let least = Array.fold_left (+) 0 mi in
  let count = (x - least) / mi.(0) in
  let res = n + count in
  Printf.printf "%d\n" res 
    

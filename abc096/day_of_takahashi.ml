let () =
  let a, b = Scanf.scanf "%d %d" (fun a b -> a, b) in
  let result =
    if a <= b then
      a 
    else
      a - 1
  in
  Printf.printf "%d\n" result
    
      

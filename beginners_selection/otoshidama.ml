let () =
  let n, y = Scanf.scanf "%d %d" (fun x y -> x, y) in
  let rec loop a b =
    if a > n then (-1, -1, -1)
    else if a + b > n then loop (a+1) 0
    else if 10*a + 5*b + (n-a-b) = y/1000 then (a, b, n-a-b)
    else
      loop a (b+1)
  in
  let a, b, c = loop 0 0 in
  Printf.printf "%d %d %d" a b c
                  
                                                   

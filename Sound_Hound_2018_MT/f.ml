let () =
  let a, b = Scanf.scanf "%d %d" (fun x y -> x, y) in
  Printf.printf "%s\n" (if a + b = 15 then
                          "+"
                        else if a * b = 15 then 
                          "*"
                        else
                          "x")

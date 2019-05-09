let () =
  let result = ref 0 in
  let x =
    Scanf.scanf "%d" (fun x -> x) in
  let expo = Array.make (x+1) 0 in
  expo.(1) <- 1;

  for b = 2 to x do
    let v = ref (b * b) in
    while !v <= x do
      expo.(!v) <- 1;
      v := b * !v;
    done;
  done;

  for i = 0 to x do
  if expo.(i) = 1 then
    result := i
done;
  Printf.printf "%d\n" !result
    

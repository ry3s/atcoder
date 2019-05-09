
let () =
  let n = Scanf.scanf "%d " (fun x -> x) in
  let s = Array.init n (fun _ -> Scanf.scanf "%c"
                                   (fun x -> x)) in
  let result = ref n in
  let left = Array.make n 0 in
  let right = Array.make n 0 in
  
  for i = 1 to (n-1) do
    if s.(i-1) = 'W' then
      left.(i) <- left.(i-1) + 1
    else
      left.(i) <- left.(i-1)
  done;
  for i = 1 to (n-1) do
    let i = n-1-i in
    if s.(i+1) = 'E' then
      right.(i) <- right.(i+1) + 1
    else
      right.(i) <- right.(i+1)
  done;
  for i = 0 to (n-1) do
    let res = left.(i) + right.(i) in
    if res < !result then
      result := res
  done;
  Printf.printf "%d\n" !result


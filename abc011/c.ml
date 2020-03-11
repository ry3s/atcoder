let rec loop i arr =
  if i = 0 then
    (if arr.(i) >= 0 then "YES" else "NO")
  else if arr.(i) >= 0 then
    begin
      if i >= 3 && arr.(i - 3) <> -2 then
        arr.(i - 3) <- max arr.(i - 3) (arr.(i) - 1);
      if i >=2 && arr.(i - 2) <> -2 then
        arr.(i - 2) <- max arr.(i - 2) (arr.(i) - 1);
      if i >= 1 && arr.(i - 1) <> -2 then
        arr.(i - 1) <- max arr.(i - 1) (arr.(i) - 1);
      loop (i - 1) arr
    end
  else
    loop (i - 1) arr

let n = read_int ()
let arr = Array.make (n + 1) (-1)
let () =
  arr.(n) <- 100;
  for i = 1 to 3 do
    let v = read_int () in
    if v <= n then arr.(v) <- -2
  done;

  loop n arr |> print_endline

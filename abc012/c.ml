let n = read_int ()
let m = 2025 - n
let () =
  for i = 1 to 9 do
    if m mod i = 0 && m / i <= 9 then
      Printf.printf "%d x %d\n" i (m / i)
  done

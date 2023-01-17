library ieee;
use ieee.std_logic_1164.all;

entity gtob is
  port(
g: in std_logic_vector(3 downto 0);
b:out std_logic_vector(3 downto 0)
);
end gtob;
architecture gtob_ar of gtob is
begin
b(3)<= g(3);
b(2)<=g(3) xor g(2);
b(1)<= g(3) xor g(2)xor g(1);
b(0)<= g(3) xor g(2)xor g(1)xor g(0);
end gtob_ar;
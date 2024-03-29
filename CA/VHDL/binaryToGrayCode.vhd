library ieee;
use ieee.std_logic_1164.all;

entity btog is
  port(
b: in std_logic_vector(3 downto 0);
g:out std_logic_vector(3 downto 0)
);
end btog;
architecture btog_ar of btog is
begin
g(3)<= b(3);
g(2)<=b(3) xor b(2);
g(1)<= b(2)xor b(1);
g(0)<=b(1) xor b(0);
end btog_ar;

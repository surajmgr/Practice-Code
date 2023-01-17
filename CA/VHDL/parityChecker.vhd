-- 4 bit parity checker :
library IEEE;
use IEEE.std_logic_1164.all;
entity parity is
port ( IE : in std_logic; -- Even input IE active high
IO : in std_logic; -- Odd input IO active high
OE : out std_logic; -- Even output OE active high
OO : out std_logic; -- Odd output OO active high
D : in std_logic_vector(3 downto 0));
end entity;
architecture parity_arch of parity is
signal TEMP : std_logic;
begin
TEMP <= D(0) xor D(1) xor D(2) xor D(3);
OE <= TEMP xor IE;
OO <= TEMP xor IO;
end parity_arch;

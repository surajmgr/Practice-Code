library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
USE ieee.numeric_std.ALL;
entity RAM_32X8 is
port(
 address: in std_logic_vector(4 downto 0); 
 data_in: in std_logic_vector(7 downto 0);
 write_in: in std_logic; 
 clock: in std_logic; 
 data_out: out std_logic_vector(7 downto 0)
);
end RAM_32X8;
architecture Behav of RAM_32X8 is
type ram_array is array (0 to 31 ) of std_logic_vector (7 downto 0);
signal ram_data: ram_array :=(
   b"10000000",b"01001101",x"77",x"67",
   x"99",x"25",x"00",x"1A", 
   x"00",x"00",x"00",x"00",
   x"00",x"00",x"00",x"00",
   x"00",x"0F",x"00",x"00",
   x"00",x"00",b"00111100",x"00",
   x"00",x"00",x"00",x"00",
   x"00",x"00",x"00",x"1F"
   ); 
begin
process(clock)
begin
 if(rising_edge(clock)) then
 if(write_in='1') then 
 ram_data(to_integer(unsigned(address))) <= data_in;
  end if;
 end if;
end process;
 data_out <= ram_data(to_integer(unsigned(address)));
end Behav;

-- For Output:
-- For read
-- Address:11111
-- Data in:10101010
-- Write:1
-- Clock:1
-- Run Output will be 00011111
-- For write
-- Address 11111
-- Data in: 10101010
-- Write:1
-- Clock:0
-- Output will be: 10101010
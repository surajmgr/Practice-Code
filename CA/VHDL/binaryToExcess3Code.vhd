library IEEE;
use IEEE.STD_LOGIC_1164.all;
entity Binary_to_Excess3 is     
    port (
        din : in STD_LOGIC_VECTOR(3 downto 0);
        dout : out STD_LOGIC_VECTOR(3 downto 0)
        );
end Binary_to_Excess3;

architecture Binary_to_excess3_arc of Binary_to_Excess3 is
begin
    with din select
    dout <= "0011" when "0000",
        "0100" when "0001",
        "0101" when "0010",
        "0110" when "0011",
        "0111" when "0100",
        "1000" when "0101",
        "1001" when "0110",
        "1010" when "0111",
        "1011" when "1000",
        "1100" when "1001",
        "ZZZZ" when others;
end Binary_to_excess3_arc;
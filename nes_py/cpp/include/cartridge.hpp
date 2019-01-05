#ifndef CARTRIDGE_H
#define CARTRIDGE_H
#include <vector>
#include <string>
#include <cstdint>

using Address = std::uint16_t;

class Cartridge {

private:
    /// the PRG ROM
    std::vector<uint8_t> m_PRG_ROM;
    /// the CHR ROM
    std::vector<uint8_t> m_CHR_ROM;
    /// the name table mirroring mode
    uint8_t m_nameTableMirroring;
    /// the mapper ID number
    uint8_t m_mapperNumber;
    /// whether this cartridge uses extended RAM
    bool m_extendedRAM;
    /// whether this cartridge has CHR RAM
    // bool m_chrRAM;

public:
    /// Initialize a new cartridge
    Cartridge() : m_nameTableMirroring(0), m_mapperNumber(0), m_extendedRAM(false) { };

    /// Load a ROM file into the cartridge and build the corresponding mapper.
    bool loadFromFile(std::string path);

    /// Return the ROM data.
    const std::vector<uint8_t>& getROM() { return m_PRG_ROM; };

    /// Return the VROM data.
    const std::vector<uint8_t>& getVROM() { return m_CHR_ROM; };

    /// Return the mapper ID number.
    uint8_t getMapper() { return m_mapperNumber; };

    /// Return the name table mirroring mode.
    uint8_t getNameTableMirroring() { return m_nameTableMirroring; };

    /// Return a boolean determining whether this cartridge uses extended RAM.
    bool hasExtendedRAM() { return m_extendedRAM; };

};

#endif // CARTRIDGE_H

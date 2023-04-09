#include "../includes/memory.hpp"

Memory::Memory()
{
    this->LoadStack();
}

Memory::~Memory()
{
    this->stack.clear();
}

void Memory::Write(address address, data data)
{
    this->stack[DecimalConverter::FromBinary(address)] = data;
}

data Memory::Read(address address)
{
    // std::cout << "Debug Read: " << address << "\n";
    // std::cout << "Debug Read: " << DecimalConverter::FromBinary(address) << "\n";
    return this->stack[DecimalConverter::FromBinary(address)];
}

void Memory::LoadStack()
{
    for(int i = 0; i < SETTING::MAX_MEMORY; i++)
    {
        this->stack.push_back(model::template_8bits);
    }
}

void Memory::LoadProgram(std::vector<std::string> opcodes)
{
    for(int i = 0; i < opcodes.size(); i++)
    {
        if(opcodes[i].size() > 1)
        {
            // std::cout << "Debug: " << opcodes[i] << " | " << i << "\n";
            this->stackProgram.push_back(opcodes[i]);
        }
    }
}

std::vector<data> Memory::ReadChunk(int start, int end)
{
    std::vector<data> chuck;

    for(int i = start; i <= end; i++)
    {
        chuck.push_back(this->stack[i]);
    }

    return chuck;
}

void Memory::WriteChunk(int address, std::vector<data> chunk)
{
    int pointer = address;

    for(auto byte : chunk)
    {
        this->stack[pointer] = byte;
        pointer++;
    }
}

data Memory::ReadCommand(int address)
{
    return this->stackProgram[address];
}
/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Declaration of the Parser class
*/

#if !defined(_PARSER_HPP)
#define _PARSER_HPP

#include <string>
#include <map>
#include <exception>
#include <fstream>
#include "Component.hpp"

#define SPACE(c) (c == ' ')
#define TAB(c) (c == '\t')

namespace Parser
{

    using container_setting_t = std::vector<Component::ComponentSetting>;
    using container_link_t = std::vector<Component::Link>;

    class Parser
    {
    public:
        Parser(const std::string &filename);
        ~Parser();

        const container_setting_t Parse();
        void ReadFile();
        std::ifstream OpenFile() const;
        void AddLinksToChipsetInfo(const container_link_t &allLinks, container_setting_t &components);
        void HandleChipsets(unsigned int &i, container_setting_t &ret);
        void HandleLinks(unsigned int &i, container_link_t &allLinks);

    private:
        std::string _filename;
        std::vector<std::string> _lines;
    };

    class LineParser
    {
    public:
        LineParser(const std::string &line);
        ~LineParser();

        const std::string &GetLine() const;

        void ClearLine();
        void RemoveComment();

        nts::Type GetType(const std::string &typeStr) const;
        Component::ComponentSetting GetInfoComponent() const;
        Component::Link GetLink() const;
        std::map<std::string, std::string> SplitLineInTwo() const;

    private:
        std::string _line;
    };

    class Checker
    {
    public:
        Checker(const container_setting_t &chipsetInfo, const container_link_t &allLinks);
        Checker(const container_setting_t &chipsetInfo);
        Checker(const container_link_t &allLinks);
        Checker(const std::string &line);
        ~Checker();

        void Check();
        void CheckNames() const;
        void CheckType() const;
        void CheckOutputs() const;
        void CheckLinksMultiple() const;

        bool IsUseless() const;

    private:
        container_setting_t _chipsetInfo;
        container_link_t _allLinks;
        std::string _line;
    };

} // Parser

#endif // _PARSER_HPP

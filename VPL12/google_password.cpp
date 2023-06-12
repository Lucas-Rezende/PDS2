#include "google_password.hpp"

#include <iostream>
#include <regex> // Me permite impor requisitos a criação de senha

void GooglePassword::insert(const std::string &url,
                            const std::string &login,
                            const std::string &password)
{
    // TODO: Implemente este metodo
    /**
     * Lembre-se que as credenciais so podem ser inseridas com as seguintes
     * condicoes:
     * Condicao 1: A senha nao pode ter a seguencia '123456'.
     * Condicao 2: A senha nao pode ter mais do que 50 caracteres (no maximo 50).
     * Condicao 3: A senha nao pode ter menos do que 6 caracteres (no minimo 6).
     * Condicao 4: A senha nao pode ter caracteres em branco ' '.
     *
     * Exemplos de senhas invalidas:
     * 123456
     * test_123456
     * 123456_test
     * test_123456_test
     * senha test
     */

    if (GooglePassword::checkPassword(password) == true)
    {
        m_passwords.insert({url, Usuario(login, password)});
    }
}

void GooglePassword::remove(const std::string &url)
{
    // TODO: Implemente este metodo
    m_passwords.erase(url);
}

void GooglePassword::update(const std::string &url,
                            const std::string &login,
                            const std::string &old_password,
                            const std::string &new_password)
{
    // TODO: Implemente este metodo
    /**
     * Caso a url nao seja encontrada, o metodo update deve ser ignorado, ou seja,
     * este metodo nao pode inserir novas credenciais. Alem disso, as informacoes
     * do usuario so podem ser atualizadas se a senha antiga for igual a senha
     * atual. Nao esqueca de verificar se o novo password tambem e valido.
     */
    auto it = m_passwords.find(url);
    if (it != m_passwords.end())
    {
        // it->first refere a chave
        // it->second refere o valor
        if (it->second.getPassword() == old_password && GooglePassword::checkPassword(new_password))
        {
            it->second.setLogin(login);
            it->second.setPassword(new_password);
        }
    }
}

void GooglePassword::printPasswords()
{
    // TODO: Implemente este metodo
    /**
     * Exemplo de saida:
     * www.site.com: login and password
     *
     */
    std::cout << m_passwords.size() << std::endl;
    for (const auto& entry : m_passwords)
    {
        const std::string& url = entry.first;
        const Usuario& usuario = entry.second;

        std::cout << url << ": " << usuario.getLogin() << " and " << usuario.getPassword() << std::endl;
    }
}

bool GooglePassword::checkPassword(const std::string &password) const
{
    std::regex condicoes("^(?!.*123456)(?!.*\\s).{6,50}$");
    if (std::regex_match(password, condicoes))
    {
        return true;
    }
    else
    {
        return false;
    }
}
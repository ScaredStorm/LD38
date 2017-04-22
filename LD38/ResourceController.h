#ifndef RESOURCECONTROLLER_H
#define RESOURCECONTROLLER_H

#include <map>
#include <string>
#include <utility>

namespace Core
{
	template<typename ResourceType>
	class ResourceController
	{
	public:
		ResourceController(std::string&& path, std::string&& extension) : m_path(path), m_extension(extension) {}
		ResourceController(const ResourceController& rc) = delete;
		ResourceController(ResourceController&& rc) = delete;
		ResourceController& operator= (const ResourceController& rc) = delete;
		ResourceController& operator= (ResourceController&& rc) = delete;
		~ResourceController() {}

		ResourceType& add(const std::string& name)
		{
			std::string path = m_path + name + m_extension;
			ResourceType r;
			r.loadFromFile(path);
			m_res.insert(std::make_pair(name, r));
			return m_res.at(name);
		}

		void remove(const std::string& name)
		{
			if (m_res.find(name) != m_res.end())
			{
				m_res.erase(name);
			}
		}

		ResourceType& get(const std::string& name)
		{
			if (m_res.find(name) != m_res.end())
			{
				return m_res.at(name);
			}
			return add(name);
		}

		ResourceType& operator[] (const std::string& name)
		{
			return get(name);
		}

	private:
		std::string m_path;
		std::string m_extension;
		std::map<std::string, ResourceType> m_res;
	};
}

#endif /* RESOURCECONTROLLER_H */

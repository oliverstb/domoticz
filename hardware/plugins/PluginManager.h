#pragma once

//
//	Domotoicz Plugin System - Dnpwwo, 2016
//

#include "../DomoticzHardware.h"

namespace Plugins {

	class CPluginSystem
	{
	private:
		bool	m_bEnabled;
		bool	m_bAllPluginsStarted;
		int		m_iPollInterval;

		static std::map<int, CDomoticzHardwareBase*>	m_pPlugins;

		boost::thread* m_thread;
		volatile bool m_stoprequested;
		boost::mutex m_mutex;

		void Do_Work();

	public:
		CPluginSystem();
		~CPluginSystem(void);

		bool StartPluginSystem();
		void BuildManifest();
		CDomoticzHardwareBase* RegisterPlugin(const int HwdID, const std::string &Name, const std::string &PluginKey);
		void	 DeregisterPlugin(const int HwdID);
		bool StopPluginSystem();
		void AllPluginsStarted() { m_bAllPluginsStarted = true; };
		static void SendNotification(const std::string &, const std::string &, const std::string &, int, const std::string &);
	};
};


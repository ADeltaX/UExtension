using System;
using Windows.UI.Xaml.Controls;
using UExtension;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace UNextApp
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        readonly UserInteractionMode uwu;

        public MainPage()
        {
            this.InitializeComponent();
            uwu = new UserInteractionMode();
            uwu.DesktopTabletModeEvent += Uwu_TabletModeEvent;
            var lol = uwu.GetSlateState();
        }

        private async void Uwu_TabletModeEvent(object sender, UserInteractionType e)
        {
            await Dispatcher.RunAsync(Windows.UI.Core.CoreDispatcherPriority.Normal, () => 
            {
                txt.Text = e.ToString();
            });
        }

        private void Button_Click(object sender, Windows.UI.Xaml.RoutedEventArgs e)
        {
            //unsub
            uwu.DesktopTabletModeEvent -= Uwu_TabletModeEvent;
        }

        private void Button_Click_1(object sender, Windows.UI.Xaml.RoutedEventArgs e)
        {
            uwu.DesktopTabletModeEvent += Uwu_TabletModeEvent;
        }
    }
}
